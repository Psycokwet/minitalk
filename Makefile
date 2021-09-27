NAME_SERV			=	server
NAME_CLI			=	client
BONUS_SERV			=	server_bonus
BONUS_CLI			=	client_bonus

BONUS 				=   bonus

SRC_PATH			= ./srcs/
OBJ_PATH			= bin/
OBJ_BONUS_PATH		= bin/bonus/

SERVER_PATH		= server/
CLIENT_PATH		= client/
COMMON_PATH		= common/

CFLAGS		+=	-W -Wall -Wextra -D BUFFER_SIZE=32 -g3 #-Werror  -pedantic 		## '+=' allow to keep default flags.

SERVER_FILES				=	
CLIENT_FILES				=	send.c
ifdef WITH_BONUS
	CFLAGS	+= -DBONUS -DIF_BONUS=true

	SERVER_FILES				+=	main_bonus.c
	CLIENT_FILES				+=	main_bonus.c
	OBJ_PATH	= $(OBJ_BONUS_PATH)
	NAME_CLI	=	$(BONUS_CLI)
	NAME_SERV	=	$(BONUS_SERV)
else
	CFLAGS	+= -DIF_BONUS=false
	SERVER_FILES				+=	main.c
	CLIENT_FILES				+=	main.c
endif


OBJ_PATHS_INIT			=	$(addprefix $(OBJ_PATH),$(SERVER_PATH) 	\
													$(CLIENT_PATH) 	\
													$(COMMON_PATH))
OBJ_PATHS_INIT			+= 	$(OBJ_PATH)
## No need for a \ on the last line
HEADERS_FILES				=	main.h
COMMON_FILES				=	ft_atoi.c \
								ft_isdigit.c \
								ft_itoa.c \
								ft_putchar_fd.c \
								ft_putnbr_fd.c \
								ft_putstr_fd.c \
								ft_strlen.c \
								ft_strncmp.c \
								parse_value.c

SRC_FILES_CLI += $(addprefix $(CLIENT_PATH), $(CLIENT_FILES))
SRC_FILES_CLI += $(addprefix $(COMMON_PATH), $(COMMON_FILES))

SRC_FILES_SERV += $(addprefix $(SERVER_PATH), $(SERVER_FILES))
SRC_FILES_SERV += $(addprefix $(COMMON_PATH), $(COMMON_FILES))


OBJREGULAR_FILES_CLI	= 	$(SRC_FILES_CLI:.c=.o)  ## get all .o names from .c names
OBJREGULAR_FILES_SERV	= 	$(SRC_FILES_SERV:.c=.o)  ## get all .o names from .c names


SRC_CLI		= $(addprefix $(SRC_PATH), $(SRC_FILES_CLI))
SRC_SRV 	= $(addprefix $(SRC_PATH), $(SRC_FILES_SERV))
OBJ_CLI 	= $(addprefix $(OBJ_PATH), $(OBJREGULAR_FILES_CLI))
OBJ_SRV 	= $(addprefix $(OBJ_PATH), $(OBJREGULAR_FILES_SERV))

CC			=	clang

LDFLAGS		=	

RM			= 	rm -f

all					:	 $(OBJ_PATHS_INIT) $(NAME_CLI)	$(NAME_SERV)

$(OBJ_PATH)%.o	:	$(SRC_PATH)%.c $(HEADERS_FILES)
	$(CC) -o $@ -c $< $(CFLAGS)  $(INC) 

$(OBJ_PATHS_INIT)	:
	mkdir -p  $@  

$(NAME_CLI)			: 	$(OBJ_CLI) 
	$(CC) -o $(NAME_CLI) $(OBJ_CLI) $(LDFLAGS)  $(INC) 

$(NAME_SERV)			: 	$(OBJ_SRV) 
	$(CC) -o $(NAME_SERV) $(OBJ_SRV) $(LDFLAGS)  $(INC) 

$(BONUS)		:
	$(MAKE) WITH_BONUS=1 all

clean_local		:									## delete all .o
	$(RM) -rf $(OBJ_PATH) $(OBJ_BONUS_PATH)

clean			: clean_local							## delete all .o

fclean			:	clean_local							## clean + delete executable
	$(RM) $(NAME_SERV) $(NAME_CLI) $(BONUS_SERV) $(BONUS_CLI)		

re				:	fclean all							## delete all .o and recompile all. Must use when editing a .h

.PHONY			:	all bonus clean fclean re
## voir dependances plus tard 
