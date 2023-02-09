namespace api_tests;

public class ProductDto
{
    public ProductDto(int id, int categoryId, string title, string alias, string content, int price, int oldPrice, int status, string keywords, string description, string hit)
    {
        this.id = id;
        category_id = categoryId;
        this.title = title;
        this.alias = alias;
        this.content = content;
        this.price = price;
        old_price = oldPrice;
        this.status = status;
        this.keywords = keywords;
        this.description = description;
        this.hit = hit;
    }

    private int id { get; set; }
    private int category_id { get; set; }
    private string title { get; set; }
    private string alias { get; set; }
    private string content { get; set; }
    private int price { get; set; }
    private int old_price { get; set; }
    private int status { get; set; }
    private string keywords { get; set; }
    private string description { get; set; }
    private  string hit { get; set; }
}