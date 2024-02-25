document.getElementById('emailForm').addEventListener('submit', function(event) {
    event.preventDefault(); 
  
    const emailInput = document.getElementById('emailInput');
    const emailValue = emailInput.value.trim(); 
  
    if (emailValue === '') {
      alert('Please enter an email address');
    } else {
      
      console.log('Email address:', emailValue);
    }
  });