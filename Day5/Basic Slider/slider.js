document.addEventListener("DOMContentLoaded", function() {
    const images = [
        "image1.jpg",
        "image2.jpg",
        "image3.jpg"
    ];
    let currentIndex = 0;
    const sliderImage = document.querySelector('.slider-image');

    function showImage(index) {
        if (index < 0) {
            currentIndex = images.length - 1;
        } else if (index >= images.length) {
            currentIndex = 0;
        }
        sliderImage.src = images[currentIndex];
    }

    window.changeSlide = function (increment) {
        currentIndex += increment;
        showImage(currentIndex);
    };

    showImage(currentIndex);
});