document.addEventListener("DOMContentLoaded", function() {
    const inputField = document.getElementById('inputField');
    const displayButton = document.getElementById('displayButton');
    const displayContent = document.getElementById('displayContent');

    displayButton.addEventListener('click', function() {
        const inputText = inputField.value;
        displayContent.textContent = inputText;
    });
});