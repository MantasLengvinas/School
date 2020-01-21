module.exports = app => {
    
    app.get('/', (req, res) => {
        res.render('./pages/maintenance', {title: "Maintenance"});
    });

    app.get('/dev', (req, res) => {
        res.render('./pages/index', {title: "Welcome"});
    })

}