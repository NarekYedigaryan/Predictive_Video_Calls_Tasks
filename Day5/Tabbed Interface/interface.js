document.addEventListener("DOMContentLoaded", function () {
    const tabs = {
        tab1: "Content for Tab 1",
        tab2: "Content for Tab 2",
        tab3: "Content for Tab 3"
    };

    const tabButtons = document.querySelectorAll(".tab-button");
    const tabContents = document.querySelectorAll(".tab-content");

    tabButtons.forEach(button => {
        button.addEventListener("click", () => {
            const tabId = button.getAttribute("data-tab");

            tabButtons.forEach(btn => btn.classList.remove("active"));
            tabContents.forEach(content => content.style.display = "none");

            button.classList.add("active");
            document.getElementById(tabId).style.display = "block";

            if (!document.getElementById(tabId).innerHTML) {
                document.getElementById(tabId).innerHTML = tabs[tabId];
            }
        });
    });

    tabButtons[0].click();
});