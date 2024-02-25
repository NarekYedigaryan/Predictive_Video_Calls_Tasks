const clickButton = document.getElementById('clickButton');
const displayArea = document.getElementById('displayArea');

let clickCount = 0;

clickButton.addEventListener('click', () => {
  clickCount++;
  displayArea.textContent = clickCount;
});