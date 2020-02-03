
//includes
let express  = require("express")
let app = express()
let path = require("path")
let parser = require("body-parser")
let fs = require('fs')
var http = require('http').Server(app)
var io = require('socket.io')(http)

//Variables
let port = 8080;

function recursiveRoutes(folderName) {
    fs.readdirSync(folderName).forEach(function(file) {

        var fullName = path.join(folderName, file);
        var stat = fs.lstatSync(fullName);

        if (stat.isDirectory()) {
            recursiveRoutes(fullName);
        } else if (file.toLowerCase().indexOf('.js')) {
            require('./' + fullName)(app, io);
            console.log("require('" + fullName + "')");
        }
    });
}
recursiveRoutes('routes');

//App settings
app.set('view engine', 'ejs');
app.set('trust proxy', true);

require('./routes/public.js');

app.use(parser.urlencoded({extended: true}));
app.use(express.static(__dirname + '/public'));


http.listen(port, () => {
    console.log(`Server is now running.. Port: ${port}.. `);
});

