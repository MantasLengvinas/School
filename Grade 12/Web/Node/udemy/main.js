
//includes
let express  = require("express")
let path = require("path")
let parser = require("body-parser")

//Variables
let app = express();
app.set('view engine', 'ejs');
app.use(parser.urlencoded({extended: true}));

//Load views
app.get('/', (req, res) => {
    res.render("pages/index");
});

app.get('/contact', (req, res) => {
    res.render("pages/contact");
})

app.post('/contact', (req, res) =>{
    let fn = req.body.firstname;
    let ln = req.body.lastname;

    res.send(fn + " " + ln);
})

app.listen(8080, () => {
    console.log("Server is runing");
});
