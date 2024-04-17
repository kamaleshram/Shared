from Crypto.Hash import SHA256
from Crypto.PublicKey import DSA
from Crypto.Signature import DSS
import os

class HORSTSignature:
    def __init__(self, hash_func=SHA256, num_levels=5, w=16):
        self.hash_func = hash_func
        self.num_levels = num_levels
        self.w = w

    def generate_keypair(self):
        key = DSA.generate(2048)
        return key, key.publickey()

    def sign(self, message, private_key):
        key = private_key
        # key = private_key.export_key(format='DER')
        hash_value = self.hash_func.new(message)
        signature = []
        for i in range(self.num_levels):
            index = int.from_bytes(hash_value.digest()[i*self.w:(i+1)*self.w], byteorder='big') % (2 ** self.w)
            signer = DSS.new(key, 'fips-186-3')
            signature.append(signer.sign(hash_value))
        return signature

    def verify(self, message, signature, public_key):
        key = public_key
        hash_value = self.hash_func.new(message)
        for i in range(self.num_levels):
            index = int.from_bytes(hash_value.digest()[i*self.w:(i+1)*self.w], byteorder='big') % (2 ** self.w)
            verifier = DSS.new(key, 'fips-186-3')
            try:
                verifier.verify(hash_value, signature[i])
            except ValueError:
                return False
        return True

# horst = HORSTSignature()
# private_key, public_key = horst.generate_keypair()
# # public_key = private_key.publickey()

# message = b"Hello, world!"
# print("private_key: ", type(private_key))
# signature = horst.sign(message, private_key)
# print("Signature:", signature)

# is_verified = horst.verify(message, signature, public_key)
# print("Verification result:", is_verified)
