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
