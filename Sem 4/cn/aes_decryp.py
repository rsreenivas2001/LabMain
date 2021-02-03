from Crypto.Cipher import AES


def decryption(key_, file_name):
     file_in = open(file_name, "rb")
     nonce, ciphertext = [file_in.read(x) for x in (16, -1)]
     cipher = AES.new(key_, AES.MODE_EAX, nonce)
     decrypted_data = cipher.decrypt(ciphertext)
     return decrypted_data.decode("utf-8")


if __name__ == '__main__':
    file = 'output.txt'
    key_file = open('key.txt', 'rb')
    key = key_file.read()
    data = decryption(key, file)
    print(data)