# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -I./include

# Diretórios
SRCDIR = src
OBJDIR = obj
BINDIR = bin
# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall -I./include

# Diretórios
SRCDIR = src
OBJDIR = obj

# Nome do executável
EXECUTABLE = forca

# Arquivos fonte
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Alvo padrão
all: $(EXECUTABLE)

# Alvo para o executável
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

# Alvo para objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Alvo para limpar arquivos gerados
clean:
	rm -rf $(OBJDIR) $(EXECUTABLE)

# Cria o diretório de objetos, caso não exista
$(shell mkdir -p $(OBJDIR))

.PHONY: all clean
