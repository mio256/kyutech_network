# コンパイルオプション
CC = gcc

# ターゲットバイナリ
SERVER = server.out
CLIENT = client.out

# ソースファイル
SERVER_SRC = server.c
CLIENT_SRC = client.c

# デフォルトのターゲット
all: $(SERVER) $(CLIENT)

# server.out のコンパイルルール
$(SERVER): $(SERVER_SRC)
	$(CC) -o $(SERVER) $(SERVER_SRC)

# client.out のコンパイルルール
$(CLIENT): $(CLIENT_SRC)
	$(CC) -o $(CLIENT) $(CLIENT_SRC)

# 実行ルール
run: $(SERVER) $(CLIENT)
	./$(SERVER) &
	./$(CLIENT)

# クリーンアップルール
clean:
	rm -f $(SERVER) $(CLIENT)
