document.addEventListener("DOMContentLoaded", function() {
    const colorButtons = document.querySelectorAll('.colorButton');

    colorButtons.forEach(function(button) {
        button.addEventListener('click', function() {
            const color = this.dataset.color;
            document.body.style.backgroundColor = color;
        });
    });
});