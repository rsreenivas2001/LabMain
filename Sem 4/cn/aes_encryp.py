from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes


def encryption(data_, file_name):
    _key = get_random_bytes(32)
    cipher = AES.new(_key, AES.MODE_EAX)
    decoded_data = cipher.encrypt(data_)
    output_file = open(file_name, "wb")
    output_key = open("key.txt", "wb")
    [output_file.write(x) for x in (cipher.nonce, decoded_data)]
    output_key.write(_key)
    output_file.close()
    output_key.close()
    return _key


if __name__ == '__main__':
    with open('input.txt') as f:
        data = f.read().encode("utf-8")
    file = 'output.txt'
    key = encryption(data, file)
    print("successfully encrypted!")