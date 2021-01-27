#!/usr/bin/python3
''' Module Count '''

import requests


def count_words(subreddit, word_list):
    ''' def counf world '''
    headers = {"User-Agent": ""}
    the_url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    data = requests.get(the_url, headers=headers, allow_redirects=False).json()
    print(data)
