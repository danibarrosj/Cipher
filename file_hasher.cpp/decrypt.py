def caesar_decrypt(text, shift):
    decrypted_text = ""
    for char in text:
        if char.isalpha():
            base = ord('A') if char.isupper() else ord('a')
            decrypted_text += chr((ord(char) - base - shift) % 26 + base)
        else:
            decrypted_text += char  # Keep spaces and punctuation unchanged
    return decrypted_text

# Read encrypted text
try:
    with open("encrypted.txt", "r") as file:
        encrypted_message = file.read().strip()
except FileNotFoundError:
    print("Error: encrypted.txt not found! Run the C++ encryptor first.")
    exit()

shift = int(input("Enter shift key used for encryption: "))  # Ask for shift key
decrypted_message = caesar_decrypt(encrypted_message, shift)
print("Decrypted Message:", dec
