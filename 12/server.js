const WebSocket = require("ws"); // WebSocketパッケージの読み込み
const server = new WebSocket.Server({ port: 8080 }); // WebSocketサーバの生成、ポート番号8080を利用

server.on("connection", (ws) => {
  console.log("クライアントが接続しました");

  // クライアントからのメッセージ受信時の処理
  ws.on("message", (message) => {
    console.log("受信メッセージ:", message.toString("utf8"));

    // 全クライアントにメッセージを送信（送信元クライアントを含む）
    server.clients.forEach((client) => {
      if (client.readyState === WebSocket.OPEN) {
        client.send(message.toString("utf8"));
      }
    });
  });

  // クライアント切断時の処理
  ws.on("close", () => {
    console.log("クライアントが切断しました");
  });
});
