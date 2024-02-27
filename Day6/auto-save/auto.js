function saveFormData() {
    const formData = new FormData(document.getElementById('myForm'));
    const serializedData = JSON.stringify(Object.fromEntries(formData));
    localStorage.setItem('formData', serializedData);
  }
  
  function loadFormData() {
    const storedData = localStorage.getItem('formData');
    if (storedData) {
      const formData = JSON.parse(storedData);
      for (const key in formData) {
        document.getElementById(key).value = formData[key];
      }
    }
  }
  
  function throttle(func, limit) {
    let lastFunc;
    let lastRan;
    return function () {
      const context = this;
      const args = arguments;
      if (!lastRan) {
        func.apply(context, args);
        lastRan = Date.now();
      } else {
        clearTimeout(lastFunc);
        lastFunc = setTimeout(function () {
          if ((Date.now() - lastRan) >= limit) {
            func.apply(context, args);
            lastRan = Date.now();
          }
        }, limit - (Date.now() - lastRan));
      }
    }
  }
  
  document.querySelectorAll('input, textarea').forEach(input => {
    input.addEventListener('input', throttle(saveFormData, 1000)); // Throttle to 1 second
  });
  
  window.addEventListener('load', loadFormData);