const itemList = document.getElementById('itemList');
const listItems = itemList.getElementsByTagName('li');

for (let i = 0; i < listItems.length; i++) {
  listItems[i].addEventListener('mouseover', function() {
    this.style.color = 'red';
  });

  listItems[i].addEventListener('mouseout', function() {
    this.style.color = 'black';
  });
}