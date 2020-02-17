from PIL import Image
import numpy


#im = Image.open('eif.jpg')
##im.show()
#im_arr = numpy.array(im)
#im_arr[0][0] = [0,0,0]
#im_arr[10][10] = [0,0,0]
#imm = Image.fromarray(im_arr)
#imm.show()
#im.save("imm.png")


# def decode(im)


def encode(string, path):
    im = Image.open(path)
    image_array = numpy.array(im)
    for i in range(len(string)):
        num_of_ascii = ord(string[i])
        for j in range(num_of_ascii // 3):
            #print(i ,"asda", j)
            #print(image_array[i][j])
            image_array[i][j][0] += 1
            image_array[i][j][1] += 1
            image_array[i][j][2] += 1
            #print(image_array[i][j])
        #image_array[i][num_of_ascii // 3] = [1] * (num_of_ascii % 3) + [0] * (3 - num_of_ascii % 3)
        for a in range(num_of_ascii % 3):
            image_array[i][num_of_ascii // 3 + 1][a] +=1
    #print(image_array[0][0],"!!!!!!!!!!!!!!!!!!!!!!!!")
    imm = Image.fromarray(image_array)
    aa = numpy.array(imm)
    #print(aa[0][0],"?????????????????????")
    imm.save("im_enc.png")
    #im = Image.open("im_enc.png")
    #z = numpy.array(im)
    #print(z[0][0], "?sdgfsefsdefg??????????")



def decode(im1, im2):
    im_1 = Image.open(im1)
    image_array_1 = numpy.array(im_1)
    im_2 = Image.open(im2)
    image_array_2 = numpy.array(im_2)
    ##print(image_array_2[0][0], "!!!!!!!!!!!!!!!!!!!!!")
    #print(image_array_1[0][0], "!!!!!!!!!!!!!!!!!!!!!")
    out=""
    for i in range(len(image_array_1)):
        suma = 0
        for j in range(len(image_array_1[0])):
            #print(image_array_1[i][j])
            #print(image_array_2[i][j])
            #print(sum(image_array_1[i][j]),"aa",i)
            #print(sum(image_array_2[i][j]),"bb")
            #print(sum(image_array_2[i][j])-sum(image_array_1[i][j]))
            suma+= sum(image_array_2[i][j]) - sum(image_array_1[i][j])
        #print(suma)
        if not suma:
            break
        out += chr(suma)


    print(out)


encode("napis ss ss", "imm.png")
decode('imm.png',"im_enc.png")