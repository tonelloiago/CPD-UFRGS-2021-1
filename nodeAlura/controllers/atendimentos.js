module.exports = app => {
    app.get('/atendimentos', (request, response) => response.send('Servidor rodando, tudo ok'));
 
    app.post('/atendimentos', (request, response) => {
        console.log(request.body);
        response.send('Você está realizando um post');
    })
}