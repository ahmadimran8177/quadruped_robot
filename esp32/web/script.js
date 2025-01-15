let movementInterval = null;
let isMoving = false;
let lastCommand = null;
let stopRequested = false;

function startMovement(command) {
    // If stop was just requested, ignore new movement
    if (stopRequested) {
        stopRequested = false;
        return;
    }

    // Prevent multiple intervals from being started
    if (isMoving) return;

    isMoving = true;
    lastCommand = command;

    // Send initial command only once
    sendCommand(command);

    // Start continuous sending
    movementInterval = setInterval(() => {
        sendCommand(command);
    }, 100); // Adjust interval as needed
}

function stopMovement() {
    // Prevent sending multiple stop commands
    if (stopRequested) return;
    stopRequested = true;

    // Stop continuous sending
    if (movementInterval) {
        clearInterval(movementInterval);
        movementInterval = null;
    }

    // Reset the moving state
    isMoving = false;

    // Only send stop if there was a previous movement command
    if (lastCommand) {
        sendCommand('stop');
        lastCommand = null;
    }

    // Reset stop request after a short delay
    setTimeout(() => {
        stopRequested = false;
    }, 200);
}

function sendCommand(command) {
    fetch('/' + command)
        .then(response => response.text())
        .then(text => console.log(text))
        .catch(error => console.error('Error:', error));
}