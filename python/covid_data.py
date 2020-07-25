from bs4 import BeautifulSoup
import selenium
from requests import get

tn_url = "https://www.tn.gov/health/cedep/ncov/data/downloadable-datasets.html"
raw_html = get(tn_url)
tn_soup = BeautifulSoup(raw_html.text, 'html.parser')

links = tn_soup.find_all('a')

href = []
for link in links:
    if(link.has_attr('href')):
        href.append(link['href'])

raw_data_links = []
for link in href:
    if(link.endswith('XLSX')):
        raw_data_links.append(tn_url+link)

i = 0
for link in raw_data_links:
    print(link)
    xlsx = get(link, allow_redirects=True)
    open(str(i) + '.XLSX', 'wb').write(xlsx.content)
    i+=1
