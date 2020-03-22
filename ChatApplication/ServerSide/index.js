const express = require('express');
http = require('http');
app = express();
server = http.createServer(app);
io = require('socket.io').listen(server);
app.get('/', (req, res) => {

res.send('Chat Server is running on port 8080')
});


server.listen(8080,()=>{

console.log('Node app is running on port 8080')

});

io.on('connection',(socket)=>{
    console.log('user connected...');
    socket.on('join',function(userNickName){
        console.log(userNickName +": has join the chat...")
        socket.broadcast.emit('userjoinedthechat',userNickName+ ":has join the chat")
    });

    socket.on('messagedetection', (senderNickname,messageContent) => {
      
        console.log(senderNickname+" :" +messageContent)
 
       let  message = {"message":messageContent, "senderNickname":senderNickname}
 
        socket.emit('message', message )
 
       });


       socket.on('disconnect', function() {
        console.log( 'user has left ')
        socket.broadcast.emit( "userdisconnect" ,' user has left')
    });
});

