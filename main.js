const Particle = require('particle-api-js');
const particle = new Particle();

const auth = '...';
const deviceId = '...';
const name = 'button-clicked';

particle.getEventStream({ auth, deviceId, name }).then(function(stream) {
    stream.on('event', function(data) {
        console.log(data);
    });
});


particle.callFunction({ auth, deviceId, name: 'ledoff', argument: 'some data' });
