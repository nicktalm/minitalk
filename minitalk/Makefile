NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = src/server.c
SRCS_CLIENT = src/client.c
SRCS_SERVER_BONUS = src/server_bonus.c
SRCS_CLIENT_BONUS = src/client_bonus.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
LIBFT = lib/libft
PRINTF = lib/printf
INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf

BBlue="\033[1;34m"
BPurple="\033[1;35m"
BRed="\033[1;31m"
BGreen="\033[1;32m"
DEF_COLOR = "\033[0;39m"
BCyan = "\033[1;36m"
On_ICyan="\033[0;106m"

$(NAME_SERVER): $(OBJS_SERVER)
	@echo $(BBlue)"Compiling printf..."$(DEF_COLOR)
	@cd $(PRINTF) && $(MAKE) all
	@echo $(BPurple)"Compiling libft..."$(DEF_COLOR)
	@cd $(LIBFT) && $(MAKE) all
	@echo $(BGreen)"Compiling server..."$(DEF_COLOR)
	@cc $(OBJS_SERVER) $(INLIBFT) $(INPRINTF) -o $(NAME_SERVER) $(CFLAGS)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@echo $(BGreen)"Compiling client..."$(DEF_COLOR)
	@cd $(PRINTF) && $(MAKE) all
	@cd $(LIBFT) && $(MAKE) all
	@cc $(OBJS_CLIENT) $(INLIBFT) $(INPRINTF) -o $(NAME_CLIENT) $(CFLAGS)
	@echo $(On_ICyan)"minitalk is ready to start"$(DEF_COLOR)

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@echo $(BBlue)"Compiling printf..."$(DEF_COLOR)
	@cd $(PRINTF) && $(MAKE) all
	@echo $(BPurple)"Compiling libft..."$(DEF_COLOR)
	@cd $(LIBFT) && $(MAKE) all
	@echo $(BGreen)"Compiling server_bonus..."$(DEF_COLOR)
	@cc $(OBJS_SERVER_BONUS) $(INLIBFT) $(INPRINTF) -o $(NAME_SERVER_BONUS) $(CFLAGS)

$(NAME_CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@echo $(BGreen)"Compiling client_bonus..."$(DEF_COLOR)
	@cd $(PRINTF) && $(MAKE) all
	@cd $(LIBFT) && $(MAKE) all
	@cc $(OBJS_CLIENT_BONUS) $(INLIBFT) $(INPRINTF) -o $(NAME_CLIENT_BONUS) $(CFLAGS)
	@echo $(On_ICyan)"minitalk_bonus is ready to start"$(DEF_COLOR)

%.o:%.c
	@cc $(CFLAGS) -c $< -o $@

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
	@echo $(BRed)"Cleaning object files..."$(DEF_COLOR)
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean

fclean: clean
	@echo $(BRed)"Cleaning executable files..."$(DEF_COLOR)
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
