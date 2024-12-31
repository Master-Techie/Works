function validateEmail() {
    let email = document.getElementById('email').value;
    
    if (!email.includes('@') || !email.includes('.')) {
        alert('Please enter a valid email address');
        return false;
    }
}