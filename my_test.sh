rm magic
make
for ((i = 1; i < 8; i++));
{
    rm "output$i"
    ./magic < "test$i" > "output$i" 
}
