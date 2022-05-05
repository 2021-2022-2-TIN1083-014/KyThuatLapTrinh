
   
var list =document.querySelector('ul')
li1=document.createElement('li')
li1_text=document.createTextNode('cream')
li1.appendChild(li1_text)
list.appendChild(li1)
//ar list =document.querySelector('ul')
li2=document.createElement('li')
li2_text=document.createTextNode('kale')
li2.appendChild(li2_text)
li_one =document.getElementById('one')
list.insertBefore(li2,li_one)
//gan mau cho cac item thuoc list cool, hot xen ke (gợi í class name)
var x = document.querySelectorAll("li")
for (let i = 0; i < x.length; i++) {
 if(i % 2 == 0){
    x[i].classList.add('cool')
 }
 else
 x[i].classList.add('hot')
}
//them so luong sau by groceries (ap dung h2 span)
var span= document.createElement("span")