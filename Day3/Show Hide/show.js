const toggleButton = document.getElementById('toggleButton');
const paragraph = document.getElementById('paragraph');

toggleButton.addEventListener('click', function() {
  if (paragraph.style.display === 'none') {
    paragraph.style.display = 'block';
    toggleButton.textContent = 'Hide';
  } else {
    paragraph.style.display = 'none';
    toggleButton.textContent = 'Show';
  }
});