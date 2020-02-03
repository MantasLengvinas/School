module.exports = (app, io) => {

    let users = [];

    app.get('/', (req, res) => {
        res.render('./pages/index', {title: 'Chat room'});
    })

    io.on('connection', function(socket){
        console.log(`User joined the chat`);
        socket.on('join', (user) => {
            io.emit('join', user);
        })
        socket.on('disconnect', function(){
            console.log('User left the chat');
        });
        socket.on('message', function(msg){
            console.log(`Message: `  + msg);
            io.emit('message', msg);
        });
    });

}