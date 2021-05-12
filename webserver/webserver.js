const http = require('http').createServer(handler); //require http server, and create server with function handler()
const fs = require('fs'); //require filesystem module
const io = require('socket.io')(http) //require socket.io module and pass the http object (server)
const SerialPort = require('serialport');
const port = new SerialPort('COM13', {
  baudRate: 9600
}); //Linux uses file path, ex. '/dev/ttyACM0'
const Readline = require('@serialport/parser-readline');
const parser = port.pipe(new Readline({ delimiter: '\n' }));

http.listen(8088); //listen to port

function handler (req, res) { //create server
  fs.readFile(__dirname + '\\public\\index.html', function(err, data) { //read file index.html in public folder. Windows uses backslashes
    if (err) {
      res.writeHead(404, {'Content-Type': 'text/html'}); //display 404 on error
      return res.end("404 Not Found");
    }
    res.writeHead(200, {'Content-Type': 'text/html'}); //write HTML
    res.write(data); //write data from index.html
    console.log("webserver online");
    return res.end();
  });
}

io.sockets.on('connection', function (socket) { // WebSocket Connection
  socket.on('demo', function(value) {
    port.write(value);
    //port.flush();
    //if (value.slice(0, -4) === 'Program stopped')
      //port.close();
  });

  parser.on('data', function(data) {
    if (!isNaN(data.slice(1)) && data.startsWith('s')) {
      var servoWidth = (data.slice(1) / 180) * 100;
      socket.emit("servo value", servoWidth.toFixed(1));
    }
  });
});
