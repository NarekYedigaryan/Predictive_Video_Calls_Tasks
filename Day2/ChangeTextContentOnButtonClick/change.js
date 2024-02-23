document.addEventListener("DOMContentLoaded", function() {
    const changeButton = document.getElementById('changeButton');
    const textContent = document.getElementById('textContent');

    changeButton.addEventListener('click', function() {
        textContent.textContent = 'New Text Content';
    });
});