from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


def encryption(data_, file_name):
    _key = get_random_bytes(32)
    cipher = AES.new(_key, AES.MODE_EAX)
    decoded_data = cipher.encrypt(data_)
    output_file = open(file_name, "wb")
    [output_file.write(x) for x in (cipher.nonce, decoded_data)]
    output_file.close()
    return _key


def decryption(key_, file_name):
    file_in = open(file_name, "rb")
    nonce, ciphertext = [file_in.read(x) for x in (16, -1)]
    cipher = AES.new(key_, AES.MODE_EAX, nonce)
    decrypted_data = cipher.decrypt(ciphertext)
    return decrypted_data.decode("utf-8")


if __name__ == '__main__':
    with open('input.txt') as f:
        data = f.read().encode("utf-8")
    file = 'output.txt'
    key = encryption(data, file)
    data = decryption(key, file)
    print(data)