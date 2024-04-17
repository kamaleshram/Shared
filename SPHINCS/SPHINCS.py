from hashlib import sha256
from Crypto.Hash import SHA256
from Crypto.PublicKey import DSA
from Crypto.Signature import DSS

from HORST import HORSTSignature
from WOTSPlus import WOTSPlusSignature

from hashlib import sha256

class MerkleTree:
    def __init__(self):
        self.leaves = list()

    def add_leaf(self, leaf):
        self.leaves.append(leaf)

    def compute_root(self):
        leaves = [sha256(leaf).digest() for leaf in self.leaves]
        while len(leaves) > 1:
            if len(leaves) % 2 != 0:
                leaves.append(leaves[-1])
            leaves = [sha256(leaves[i] + leaves[i + 1]).digest() for i in range(0, len(leaves), 2)]
        return leaves[0]

    
class SPHINCS:
    def __init__(self, horst_signature, wots_signature):
        self.horst_signature = horst_signature
        self.wots_signature = wots_signature
        self.merkle_tree = MerkleTree()
        # self.horst_sk = None
        # self.wots_sk = None
        self.horst_pk = None
        self.wots_pk = None

    def generate_keypair(self):
        horst_sk, self.horst_pk = self.horst_signature.generate_keypair()
        wots_sk, self.wots_pk = self.wots_signature.generate_keypair()

        self.merkle_tree.add_leaf(self.horst_pk.export_key(format='DER'))

        for pk in self.wots_pk:
            self.merkle_tree.add_leaf(pk)
        merkle_root = self.merkle_tree.compute_root()
        return (horst_sk, wots_sk), merkle_root
    
    def sign(self, message, secret_key):
        horst_sk, wots_sk = secret_key
        horst_signature = self.horst_signature.sign(message, horst_sk)
        wots_signature = self.wots_signature.sign(message, wots_sk)
        return horst_signature, wots_signature

    def verify(self, message, signature, merkle_root):
        horst_signature, wots_signature = signature
        horst_pk, wots_pk = self.horst_pk, self.wots_pk
        return self.horst_signature.verify(message, horst_signature, horst_pk) and \
               self.wots_signature.verify(message, wots_signature, wots_pk) and \
               merkle_root == self.merkle_tree.compute_root()

if __name__ == "__main__":
    horst = HORSTSignature()
    wots = WOTSPlusSignature()
    sphincs = SPHINCS(horst, wots)
    sk, merkle_root = sphincs.generate_keypair()
    message = b"This is a message to be signed by Kamalesh using SPHINCS!"
    wrongmessage = b"Wrong Message"
    signature = sphincs.sign(message, sk)
    # print(type(signature))
    # print(signature)
    
    print("For the correct Message and Signature Combo:")
    print(f"Signature is valid: {sphincs.verify(message, signature, merkle_root)}")
    print()
    print("For the wrong Message and Signature Combo:")
    print(f"Signature is valid: {sphincs.verify(wrongmessage, signature, merkle_root)}")

