let express = require('express')
let bodyParser = require('body-parser')
let mongoose = require('mongoose')

let items = require('./routes/api/items')

//Config

let port = process.env.PORT || 8080;
let app = express();
let db = require('./config/keys').mongoURI;

//Middleware 
app.use(bodyParser.json());

//DB connection

mongoose.connect(db)
    .then(() => console.log("Database connection success"))
    .catch(err => console.log(err));

//Routes

app.use('/api/items', items);

//Server start

app.listen(port, () => console.log(`Server is now running at port ${port}`));