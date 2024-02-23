document.addEventListener("DOMContentLoaded", function() {
    const toggleButton = document.getElementById('toggleButton');
    const content = document.getElementById('content');

    toggleButton.addEventListener('click', function() {
        content.classList.toggle('hidden');
    });
});