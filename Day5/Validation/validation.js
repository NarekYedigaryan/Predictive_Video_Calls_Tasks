document.addEventListener("DOMContentLoaded", function() {
    const form = document.getElementById("myForm");
    const nameInput = document.getElementById("name");
    const emailInput = document.getElementById("email");
    const nameError = document.getElementById("nameError");
    const emailError = document.getElementById("emailError");

    form.addEventListener("submit", function(event) {
        let isValid = true;

        if (nameInput.value.trim() === "") {
            nameError.textContent = "Name is required";
            isValid = false;
        } else {
            nameError.textContent = "";
        }

        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(emailInput.value)) {
            emailError.textContent = "Invalid email format";
            isValid = false;
        } else {
            emailError.textContent = "";
        }

        if (!isValid) {
            event.preventDefault();
        }
    });
});