
class User {

   constructor(name, id, nu){
       this.name = name;
       this.id = id;
       this.nu = nu;
   }

}

module.exports = (app, io) => {

    let id = 1;
    let user = new User;

    app.get('/', (req, res) => {
        res.render('./pages/index', {title: 'Chat room'});
    })

    io.on('connection', function(socket){
        socket.on('join', (user) => {
            let u = new User(user, id, true);
            console.log(`${user} (${id}) joined the chat`);
            id++;
            io.emit('join', u);
        })
        socket.on('disconnect', function(user){
            console.log(`${user.name} left the chat`);
        });
        socket.on('message', function(msg){
            console.log(`Message: `  + msg);
            io.emit('message', msg);
        });
    });

}