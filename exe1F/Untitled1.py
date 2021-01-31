#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pytchat
import serial
import time
try:
    arduino = serial.Serial(port='COM3', baudrate=115200, timeout=.1)
    print("COM success")
except:
    print("COM error")
    pass
def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data
      

import tkinter as tk
def show_entry_fields():

    print("First Name: %s\nLast Name: %s" % (e1.get(), e2.get()))

master = tk.Tk()
master.geometry("500x180")
master.title("Shopa_2000")

tk.Label(master,

         text="Livestream link").grid(row=0)

e1 = tk.Entry(master, width = 55)
def get():
    try:
        print("proba")
        link = e1.get()
        print("dziala")
        link = link[32:43]
        print(link)
        chat = pytchat.create(video_id=link)
        while chat.is_alive():
            print("chat alive")
            for c in chat.get().sync_items():
                print("proba")
                try:
                    print(c.message)
                    i = c.message
                    value = write_read(i)
                    print(value)
                except:
                    print("pass")
                    pass
        print("chat not alive")
    except:
        print("main get error")
        pass
e1.grid(row=0, column=1, padx = 5, pady=40, ipady = 8)
tk.Button(master,
          text='Connect',
          bg='green',
          command=get).grid(row=3,
                                    column=5,
                                    sticky=tk.W,
                                    pady=5)

tk.Button(master,
          text='Test1',
          bg='red',
          command=get).grid(row=3,
                                    column=1,
                                    sticky=tk.W,
                                    pady=10)                          
tk.mainloop()

