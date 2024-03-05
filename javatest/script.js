document.addEventListener('DOMContentLoaded', function() {
    const changeMessageButton = document.getElementById('change-message');
    const welcomeSection = document.getElementById('welcome-section');

    changeMessageButton.addEventListener('click', function() {
        welcomeSection.querySelector('h2').textContent = "You've changed the message!";
        welcomeSection.querySelector('p').textContent = "Thanks for interacting with our website.";
    });
});