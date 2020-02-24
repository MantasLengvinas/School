let mongoose = require('mongoose');
let Schema = mongoose.Schema;

//Create schema

let ItemSchema = new Schema({
    name: {
        type: String,
        required: true
    },
    date: {
        type: Date,
        default: Date.now
    }
});

module.exports = Item = mongoose.model('item', ItemSchema);