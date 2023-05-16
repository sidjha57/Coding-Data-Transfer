# 0.011
# 1100000000000000000
# Unit Tests: A way of testing the smallest pieces of code in an isolated instance
from scripts.helpful_scripts import LOCAL_BLOCKCHAIN_ENVIRONMENTS
from brownie import Lottery, accounts, config, network
from scripts.deploy_lottery import deploy_lottery
from web3 import Web3
import pytest

from scripts.helpful_scripts import LOCAL_BLOCKCHAIN_ENVIRONMENTS

def test_get_entrance_fee():
    account = accounts[0]
    lottery = Lottery.deploy(
        config["networks"][network.show_active()]
        ["eth_usd_price_feed"], {"from": account},    
    )
    assert lottery.getEntranceFee() > Web3.toWei(0.010, "ether")
    assert lottery.getEntranceFee() < Web3.toWei(0.013, "ether")

# def test_get_entrance_fee():
#     if network.show_active() not in LOCAL_BLOCKCHAIN_ENVIRONMENTS:
#         pytest.skip()
#     # Arrange
#     lottery = deploy_lottery()
#     # Act
#     # 4,000 eth / usd
#     # usdEntryFee is 50
#     # 4000/1 == 50/x == 0.0125
#     expected_entrance_fee = Web3.toWei(0.0125, "ether")
#     #print(expected_entrance_fee)
#     entrance_fee = lottery.getEntranceFee()
#     # Assert
#     assert expected_entrance_fee == entrance_fee

# def test_cant_enter_unless_started():
#     if network.show


