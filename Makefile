EXEC = abstracVM

INC	= -I include

SRC = main.cpp executioner.cpp parseur.cpp errorControler.cpp operatorFactory.cpp operatorControler.cpp

OBJ	= $(SRC:%.cpp=obj/%.o)

COMPILE = clang++
FLAG = # -Wall -Werror -Wextra

all: $(EXEC)

$(EXEC): $(OBJ)
	$(COMPILE) $(FLAG) -o $@ $(OBJ) $(LIB)

%.o: src/%.cpp
	@echo -n  $< :
	@clang++ -o $@ -c $< $(FLAG)
	@echo

obj/%.o: src/%.cpp
		$(COMPILE) $(FLAG) $(INC) -o $@ -c $<

clean:
		rm -fr obj
		mkdir obj

fclean: clean
		rm $(EXEC)

re: fclean all
#TODO remmaitre le flag est fixe le re
