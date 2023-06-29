# For testing codes
# created by wei
# Feb 26, 2023
import re
from datetime import datetime

import re

text = '<p>This is <b>bold text</b>.</p>'

# Define the regular expression pattern
pattern = r'(?<=\s|>)(?<!<[/a-zA-Z_\-0-9]*)<|>(?![^<]*<\/)'

# Define the replacement string
replacement = 'lt'  # or 'gt'

# Use the re.sub() function to replace all matches
new_text = re.sub(pattern, replacement, text)

# Print the result
print(new_text)