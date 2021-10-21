NAME 	=	minitalk

CLIENT	= 	client
SERVER	=	server

CLISRC	=	climain.c
SERVSRC	=	servmain.c

CLIOBJ	=	${CLISRC:.c=.o}
SERVOBJ	=	${SERVSRC:.c=.o}

FLAG	=	-Wall -Wextra -Werror

HEADER	=	-I .

CC		=	clang

########################################################

.c.o	:	
				${CC} ${FLAG} ${HEADER} -c $< -o ${<:.c=.o}

all		:	${NAME}

${NAME}	:	${CLIOBJ} ${SERVOBJ}
				${CC}  ${FLAG} -o ${CLIENT} ${CLIOBJ}
				${CC}  ${FLAG} -o ${SERVER} ${SERVOBJ}


clean	:
				rm -rf ${CLIOBJ} ${SERVOBJ}
fclean	:	clean
				rm -rf ${CLIENT} ${SERVER}
re		:	fclean
				@make

.PHONY	:	clean fclean re make
