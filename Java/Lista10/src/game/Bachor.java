package game;

public class Bachor implements Runnable {
    public int x, y, state = 1;
    int id;
    boolean running = true;

    public Bachor(int nr)
    {
        this.id = nr;
        x = (int) Math.floor(Math.random() * Main.szerPlanszy);
        y = (int) Math.floor(Math.random() * Main.wysPlanszy);
        while((MainPanel.checkVis(x,y, nr)) == false)
        {
            x = (int) Math.floor(Math.random() * Main.szerPlanszy);
            y = (int) Math.floor(Math.random() * Main.wysPlanszy);
        }
    }

    @Override
    public void run()
    {
        while (running)
            try
            {
                System.out.println(Thread.currentThread().getName());

                if(lenMik(x, y) <=  5 && state == 1)
                {
                    if(Math.random() > 0.3)
                    {
                        movMik();
                        Thread.currentThread().sleep((int)(Math.random()* 1000 + 1000));
                    }

                    else
                    {
                        int rand = (int) (Math.random() * 4);
                        int nx = (x + MainPanel.c1[rand] + Main.szerPlanszy) % Main.szerPlanszy;
                        int ny = (y + MainPanel.c2[rand] + Main.wysPlanszy) % Main.wysPlanszy;
                        while((MainPanel.checkVis(nx,ny, id)) == false)
                        {
                            rand = (int) Math.floor(Math.random() * 4);
                            nx = (x + MainPanel.c1[rand] + Main.szerPlanszy) % Main.szerPlanszy;
                            ny = (y + MainPanel.c2[rand] + Main.wysPlanszy) % Main.wysPlanszy;
                        }
                        state = 2;
                        Thread.currentThread().sleep((int)(Math.random()* 5000 + 3000));
                        state = 1;
                        for(int px : MainPanel.c1)
                            for(int py : MainPanel.c2)
                                if(MainPanel.getPrez((x + px + Main.szerPlanszy) % Main.szerPlanszy, (y + py + Main.wysPlanszy) % Main.wysPlanszy) == true)
                                {
                                    MainPanel.setVis(x, y, 0);
                                    MainPanel.setPrez((x + px + Main.szerPlanszy) % Main.szerPlanszy, (y + py + Main.wysPlanszy) % Main.wysPlanszy, false);
                                    x = (x + px + Main.szerPlanszy) % Main.szerPlanszy;
                                    y = (y + py + Main.wysPlanszy) % Main.wysPlanszy;
                                    state = 0;
                                    running = false;
                                    continue;
                                }
                    }
                }
                else
                    Thread.currentThread().sleep((int)(Math.random()*1000 + 3000));

            }
            catch(InterruptedException ex)
            {
                System.out.println(ex);
                return;
            }
    }

    private synchronized void movMik()
    {
        if(lenMik(x, y) == 1)
            Main.koniecGry = true;
        boolean ruch = true;
        for(int px : MainPanel.c1)
            for(int py : MainPanel.c2)
                if(ruch == true)
                {
                    int nx = (x + px + Main.szerPlanszy) % Main.szerPlanszy;
                    int ny = (y + py + Main.wysPlanszy) % Main.wysPlanszy;
                    if(lenMik(nx, ny) < lenMik(x, y) && MainPanel.getVis(nx, ny) == 0)
                    {
                        MainPanel.setVis(x, y, 0);
                        x = nx;
                        y = ny;
                        MainPanel.setVis(nx, ny, id);
                        ruch = false;
                    }
                }
    }

    private synchronized int lenMik(int x, int y) {
        return Math.min(Math.abs(x - MainPanel.getMikX()), Main.szerPlanszy - Math.abs(x - MainPanel.getMikX()))
                + Math.min(Math.abs(y - MainPanel.getMikY()), Main.wysPlanszy - Math.abs(y - MainPanel.getMikY()));
    }







}
