# image filter will allow us to blur images and ImageDraw allows us to put text on image
# ImageFont allows us to add text to image
from PIL import Image, ImageDraw, ImageFont
import datetime, textwrap
# import os # to loop over the files in a directory

now = datetime.datetime.now()

# Basics, displaying and saving images
imgRapport = Image.open("rapport.jpg")
imgRapport.save("rapport.jpg") # creates a jpg version of the image

draw = ImageDraw.Draw(imgRapport)
font_bold = ImageFont.truetype("roboto_medium.ttf", 60)
font_normal = ImageFont.truetype("roboto_regular.ttf", 35)

school_name = "High School Van Rooisenveld"
student_name = "Neil"
student_surname = "Von Trador"
student_grade = 9
current_year = now.year

# Co-ordinates, Text, Color, font
draw.text((110, 30), school_name, (0, 0, 0), font=font_bold)
draw.text((350, 147), student_name, (0, 0, 0), font=font_normal)
draw.text((350, 210), student_surname, (0, 0, 0), font=font_normal)
draw.text((350, 270), str(student_grade), (0, 0, 0), font=font_normal)
draw.text((350, 320), str(current_year), (0, 0, 0), font=font_normal)

subject_font = ImageFont.truetype("roboto_regular.ttf", 32)
subject_1 = "Engineering and Graphics Design"

top = 480
draw.text((10, top), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 52), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 102), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 152), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 202), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 252), subject_1, (0, 0, 0), font=subject_font)
draw.text((10, top + 302), subject_1, (0, 0, 0), font=subject_font)

mark_font = ImageFont.truetype("roboto_medium.ttf", 37)
mark_1 = 55
right = 580
draw.text((right, top), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 52), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 102), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 152), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 202), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 252), str(mark_1), (0, 0, 0), font=mark_font)
draw.text((right, top + 302), str(mark_1), (0, 0, 0), font=mark_font)

mark_1_avg = 60
right = 750
draw.text((right, top), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 52), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 102), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 152), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 202), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 252), str(mark_1_avg), (0, 0, 0), font=mark_font)
draw.text((right, top + 302), str(mark_1_avg), (0, 0, 0), font=mark_font)

message_font = ImageFont.truetype("roboto_medium.ttf", 30)
    
my_wrap = textwrap.TextWrapper(width = 70)
extra_notes = f"{student_name} {student_surname} has passed grade {student_grade} with average marks and is promoted to grade {student_grade + 1}. Good job, welcome to the grade {student_grade + 1} class of {current_year + 1}."

# print('\n\n' + my_wrap.fill(text = single_line))

draw.text((10, 850), my_wrap.fill(text = extra_notes), (0, 0, 0), font=message_font)

imgRapport.show()