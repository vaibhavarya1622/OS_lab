/* Implementation of binary semaphores Refer:http://pages.cs.wisc.edu/~remzi/Classes/537/Fall2008/Notes/threads-semaphores.txt*/
struct semaphore
{
    int value;
    Queue<process> q;
};

void P(struct semaphore s)
{
    if (s.value == 1)
    {
        s.value = 0;
    }
    else
    {
        q.push(P)
            sleep();
    }
}

void V(struct semaphore s)
{
    if (s.q.empty())
    {
        s.value = 1;
    }
    else
    {
        q.pop();
        wakeup();
    }
}
/*implementation of counting semaphore*/
struct Semaphore
{
    int value;
    Queue<process> q;
};

void P(struct Semaphore s)
{
    s.value = s.value - 1;
    if (s.value < 0)
    {
        q.push(p);
        block();
    }
    else
        return;
}

void V(struct Semaphore s)
{
    s.value = s.value + 1;
    if (s.value <= 0)
    {
        q.pop();
        wakeup();
    }
    else
        return;
}
