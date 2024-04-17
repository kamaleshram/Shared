from Crypto.Hash import SHA256
import hashlib
import os

class WOTSPlusSignature:
    def __init__(self, hash_func=SHA256, n=32, w=16, len_ots=256):
        self.hash_func = hash_func
        self.n = n
        self.w = w
        self.len_ots = len_ots

    def generate_keypair(self):
        seed = os.urandom(self.n)
        public_key = self._generate_public_key(seed)
        return seed, public_key

    def _generate_public_key(self, seed):
        public_key = []
        for i in range(self.len_ots):
            sk = hashlib.shake_128(seed).digest(self.n)
            sk = int.from_bytes(sk, 'big')
            pk = self._wots_sk_to_pk(sk, i)
            public_key.append(pk)
        return public_key

    def _wots_sk_to_pk(self, sk, i):
        sk = sk.to_bytes(self.n, byteorder='big')
        hash_func = SHA256.new(sk)
        for _ in range(i+1):
            hash_func.update(hash_func.digest())
        return hash_func.digest()

    def sign(self, message, seed):
        hash_value = self.hash_func.new(message).digest()
        signature = []
        for i in range(len(hash_value)):
            index = (hash_value[i] * self.w) // 256
            sk = hashlib.shake_128(seed).digest(self.n)
            sk = int.from_bytes(sk, 'big')
            pk = self._wots_sk_to_pk(sk, i)
            index = (hash_value[i] * self.w) // 256
            signature.append(pk[index])
        return signature

    def verify(self, message, signature, public_key):
        hash_value = self.hash_func.new(message).digest()
        for i in range(len(hash_value)):
            index = (hash_value[i] * self.w) // 256
            if signature[i] != public_key[i][index]:
                return False
        return True

# wots_plus = WOTSPlusSignature()
# seed, public_key = wots_plus.generate_keypair()

# message = b"Hello, world!"
# signature = wots_plus.sign(message, seed)
# print("Signature:", signature)

# is_verified = wots_plus.verify(message, signature, public_key)
# print("Verification result:", is_verified)
