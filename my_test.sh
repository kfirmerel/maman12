make
for ((i = 1; i < 8; i++));
{
    ./magic < "test$i" > "output$i"
}
