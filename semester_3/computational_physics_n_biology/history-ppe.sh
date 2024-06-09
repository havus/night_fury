
mkdir -p ~/miniconda3
wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh
bash ~/miniconda3/miniconda.sh -b -u -p ~/miniconda3
~/miniconda3/bin/conda init bash
cat /root/.bashrc # export PATH="$PATH:$HOME/miniconda3/bin"

conda create --name ppe
vim ~/.bashrc 
cd $HOME$HOME
cd $HOME
cd miniconda3/
cd $HOME
vim ~/.bashrc
source ~/.bashrc
conda conda create --name ppe
conda create --name ppe
conda activate ppe
mkdir ppe
wget https://www.pythonpowerelectronics.com/releases/ppe_webapp_py3_4_4_0.zip -O ~/ppe/ppe_webapp_py3_4_4_0.zip
cd ppe/
apt install unzip
unzip ppe_webapp_py3_4_4_0.zip
cd ppe_webapp_py3_4_4_0
conda install --file requirements.txt
cd simulator_interface/
python manage.py makemigrations simulations
python manage.py migrate
vim simulator_interface/settings.py # line 27, ALLOWED_HOSTS = ['103.37.124.142']
python manage.py runserver 0.0.0.0:8000

nohup python manage.py runserver 0.0.0.0:8000 &
ps aux | grep "python manage.py runserver"
