document.addEventListener('DOMContentLoaded', function() {
    const changeMessageButton = document.getElementById('change-message');
    const welcomeSection = document.getElementById('welcome-section');

    let welcomeMessageToggled = false; // Boolean true or false (1/0).

    changeMessageButton.addEventListener('click', function() {
        if (welcomeMessageToggled) {
            welcomeSection.querySelector('h2').textContent = "Hello, visitor!";
            welcomeSection.querySelector('p').textContent = "Click the button below to change this message.";
        } else {
            welcomeSection.querySelector('h2').textContent = "You've changed the message!";
            welcomeSection.querySelector('p').textContent = "Thanks for interacting with our website.";
        }
        welcomeMessageToggled = !welcomeMessageToggled; // Toggle the welcome message state
    });
});

/*
changeMessageButton.addEventListener('click', function() {
    const randomColor = '#' + Math.floor(Math.random()*16777215).toString(16); // Generate random color
    welcomeSection.style.backgroundColor = randomColor; // Change background color
}); 

let footerVisible = true;

changeMessageButton.addEventListener('click', function() {
    footerVisible = !footerVisible; // Toggle footer visibility
    if (footerVisible) {
        footer.style.display = 'block'; // Show footer
    } else {
        footer.style.display = 'none'; // Hide footer
    }
});

let clickCount = 0;

changeMessageButton.addEventListener('click', function() {
    clickCount++;
    welcomeSection.querySelector('h2').textContent = `Button clicked ${clickCount} times!`;
});

*/